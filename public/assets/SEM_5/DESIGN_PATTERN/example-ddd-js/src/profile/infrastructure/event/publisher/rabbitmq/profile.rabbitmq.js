const { ProfilePublisher } = require('../profile.publisher');
const { 
    PROFILE_CREATED_EVENT, 
    PROFILE_UPDATED_EVENT, 
    PROFILE_DELETED_EVENT,
} = require('../../../../constant/profile.constant');

class ProfileRabbitMQPublisher extends ProfilePublisher {
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
    ProfileRabbitMQPublisher
};