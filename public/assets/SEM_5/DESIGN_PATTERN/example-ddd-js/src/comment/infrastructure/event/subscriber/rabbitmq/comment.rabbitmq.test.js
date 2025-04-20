const { COMMENT_CREATED_EVENT } = require('../../../../constant/comment.constant');
const { CommentRabbitMQSubscriber } = require('./comment.rabbitmq');

// Mock rabbitMQChannel and commentRepository
const mockChannel = {
    assertQueue: jest.fn(),
    consume: jest.fn(),
    ack: jest.fn(),
};

const mockConnection = {
    createChannel: jest.fn().mockResolvedValue(mockChannel),
}
const mockCommentRepository = {
    insert: jest.fn(),
    update: jest.fn(),
    delete: jest.fn(),
};

describe('CommentRabbitMQSubscriber', () => {
    let subscriber;

    beforeEach(() => {
        // Create an instance of CommentRabbitMQSubscriber with mock channel and repository
        subscriber = new CommentRabbitMQSubscriber(mockConnection, mockCommentRepository);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    describe('listen', () => {
        it('should listen for messages from the specified exchange and routing key', async () => {
            // Mock data
            const queue = COMMENT_CREATED_EVENT;
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
            expect(mockCommentRepository.insert).toHaveBeenCalledWith(JSON.parse(msgContent));
        });

        it('should handle errors during listening', async () => {
            // Mock data
            const queue = COMMENT_CREATED_EVENT;
            const error = new Error('Failed to consume');

            // Mock assertExchange method to throw an error
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
        it('should call onCommentCreated, onCommentUpdated, and onCommentDeleted', async () => {
            // Mock methods
            const spyOnCommentCreated = jest.spyOn(subscriber, 'onCommentCreated');
            const spyOnCommentUpdated = jest.spyOn(subscriber, 'onCommentUpdated');
            const spyOnCommentDeleted = jest.spyOn(subscriber, 'onCommentDeleted');

            // Call the run method
            await subscriber.run(mockConnection);

            // Assertions
            expect(spyOnCommentCreated).toHaveBeenCalled();
            expect(spyOnCommentUpdated).toHaveBeenCalled();
            expect(spyOnCommentDeleted).toHaveBeenCalled();
        });
    });
});
