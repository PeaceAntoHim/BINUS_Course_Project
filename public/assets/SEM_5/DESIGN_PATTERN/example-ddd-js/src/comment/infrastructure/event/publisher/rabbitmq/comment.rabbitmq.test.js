const { CommentRabbitMQPublisher } = require('./comment.rabbitmq');
const amqp = require('amqplib');

describe('CommentRabbitMQPublisher', () => {
    let mockChannel;
    let publisher;

    beforeEach(() => {
        // Mock RabbitMQ channel
        mockChannel = {
            sendToQueue: jest.fn(),
        };

        mockConnection = {
            createChannel: jest.fn().mockResolvedValue(mockChannel),
        }

        // Create an instance of CommentRabbitMQPublisher with the mock channel
        publisher = new CommentRabbitMQPublisher(mockConnection);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    describe('publish', () => {
        it('should publish a message to the exchange with the specified topic', async () => {
            // Mock data
            const topic = 'test_exchange';
            const event = { message: 'Test message' };
            
            // mockConnection.createChannel.mockResolvedValue(mockChannel);

            // Mock sendToQueue method
            mockChannel.sendToQueue.mockResolvedValue();

            // Call the publish method
            await publisher.publish(topic, event);

            // Assertions
            expect(mockChannel.sendToQueue).toHaveBeenCalledWith(topic, Buffer.from(JSON.stringify(event)));
        });

        it('should handle errors during publishing', async () => {
            // Mock data
            const topic = 'test_exchange';
            const event = { message: 'Test message' };
            const error = new Error('Failed to publish');

            // Mock sendToQueue method to throw an error
            mockChannel.sendToQueue.mockRejectedValue(error);

            // Assertions
            expect(await publisher.publish(topic, event)).toThrow(error);
        });
    });
});
