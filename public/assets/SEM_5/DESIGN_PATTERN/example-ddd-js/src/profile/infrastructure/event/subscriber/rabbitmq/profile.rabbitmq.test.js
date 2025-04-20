const { PROFILE_CREATED_EVENT } = require('../../../../constant/profile.constant');
const { ProfileRabbitMQSubscriber } = require('./profile.rabbitmq');

// Mock rabbitMQChannel and profileRepository
const mockChannel = {
    assertQueue: jest.fn(),
    consume: jest.fn(),
    ack: jest.fn(),
};

const mockConnection = {
    createChannel: jest.fn().mockResolvedValue(mockChannel),
}

const mockProfileRepository = {
    insert: jest.fn(),
    update: jest.fn(),
    delete: jest.fn(),
};

describe('ProfileRabbitMQSubscriber', () => {
    let subscriber;

    beforeEach(() => {
        // Create an instance of ProfileRabbitMQSubscriber with mock channel and repository
        subscriber = new ProfileRabbitMQSubscriber(mockConnection, mockProfileRepository);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    describe('listen', () => {
        it('should listen for messages from the specified exchange and routing key', async () => {
            // Mock data
            const queue = PROFILE_CREATED_EVENT;
            const msgContent = JSON.stringify({ message: 'Test message' });
            const msg = { content: Buffer.from(msgContent) };

            // Mock assertExchange method
            mockChannel.assertQueue.mockResolvedValue();

            // Mock assertQueue method
            mockChannel.assertQueue.mockResolvedValue({ queue: 'test_queue' });

            // Mock consume method
            mockChannel.consume.mockImplementation((queue, callback) => {
                callback(msg);
            });

            // Call the listen method
            await subscriber.listen(mockConnection, queue);

            // Assertions
            expect(mockChannel.assertQueue).toHaveBeenCalledWith(queue);
            expect(mockChannel.consume).toHaveBeenCalledWith(queue, expect.any(Function));
            expect(mockChannel.ack).toHaveBeenCalledWith(msg);
            expect(mockProfileRepository.insert).toHaveBeenCalledWith(JSON.parse(msgContent));
        });

        it('should handle errors during listening', async () => {
            // Mock data
            const queue = 'test_exchange';
            const error = new Error('Failed to consume');

            // Mock assertQueue method to throw an error
            mockChannel.assertQueue.mockRejectedValue(error);

            // Call the listen method
            await subscriber.listen(mockConnection, queue);

            // Assertions
            expect(mockChannel.assertQueue).toHaveBeenCalledWith(queue);
            expect(mockChannel.consume).not.toHaveBeenCalled();
        });
    });

    describe('onCommentCreated', () => {
        // Test similar to 'listen' method tests
    });

    describe('onCommentUpdated', () => {
        // Test similar to 'listen' method tests
    });

    describe('onCommentDeleted', () => {
        // Test similar to 'listen' method tests
    });

    describe('run', () => {
        it('should call onProfileCreated, onProfileUpdated, and onProfileDeleted', async () => {
            // Mock methods
            const spyOnProfileCreated = jest.spyOn(subscriber, 'onProfileCreated');
            const spyOnProfileUpdated = jest.spyOn(subscriber, 'onProfileUpdated');
            const spyOnProfileDeleted = jest.spyOn(subscriber, 'onProfileDeleted');

            // Call the run method
            await subscriber.run(mockConnection);

            // Assertions
            expect(spyOnProfileCreated).toHaveBeenCalled();
            expect(spyOnProfileUpdated).toHaveBeenCalled();
            expect(spyOnProfileDeleted).toHaveBeenCalled();
        });
    });
});
