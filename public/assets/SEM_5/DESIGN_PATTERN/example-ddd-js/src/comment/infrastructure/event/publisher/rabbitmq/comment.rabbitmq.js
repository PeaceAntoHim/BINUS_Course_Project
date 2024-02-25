const { CommentPublisher } = require('../comment.publisher');
const { COMMENT_CREATED_EVENT, COMMENT_UPDATED_EVENT, COMMENT_DELETED_EVENT } = require('../../../../constant/comment.constant');

class CommentRabbitMQPublisher extends CommentPublisher {
    constructor(connection) {
        super();
        this.initiate(connection);
    }

    async initiate(connection) {
        this.connection = await connection;
        this.channel = await this.connection.createChannel();
    }
    
    async publish(topic, event) {
        try {
            // Publish the message to the exchange
            this.channel.sendToQueue(topic, Buffer.from(JSON.stringify(event)));
    
            console.log(`Message published to exchange ${topic}: ${event}`);
        } catch (error) {
            console.error('Error occurred while publishing message:', error);
        }
    }
}

module.exports = {
    CommentRabbitMQPublisher
};