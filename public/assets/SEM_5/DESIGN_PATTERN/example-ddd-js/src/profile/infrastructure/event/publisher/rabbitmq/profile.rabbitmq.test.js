const { ProfileRabbitMQPublisher } = require('./profile.rabbitmq');
const amqp = require('amqplib');

describe('ProfileRabbitMQPublisher', () => {
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

        // Create an instance of ProfileRabbitMQPublisher with the mock channel
        publisher = new ProfileRabbitMQPublisher(mockConnection);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    describe('publish', () => {
        it('should publish a message to the exchange with the specified topic', async () => {
            // Mock data
            const topic = 'test_exchange';
            const event = { message: 'Test message' };
            
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
            
            // Mock sendToQueue method to throw an error
            mockChannel.sendToQueue.mockRejectedValue(new Error('Failed to publish'));
        
            // Assertions
            try {
                await publisher.publish(topic, event);
                // If the promise is resolved, fail the test
                fail('The promise should have been rejected');
            } catch (error) {
                // Check if the error message matches
                expect(error.message).toBe('Failed to publish');
            }
        });
        
    });
});
