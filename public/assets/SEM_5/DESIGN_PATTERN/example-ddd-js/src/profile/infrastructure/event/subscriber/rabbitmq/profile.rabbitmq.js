const { ProfileSubscriber } = require('../profile.subscriber')
const { 
    PROFILE_CREATED_EVENT, 
    PROFILE_UPDATED_EVENT, 
    PROFILE_DELETED_EVENT, 
    PROFILE_QUEUE_NAME, 
} = require('../../../../constant/profile.constant');

class ProfileRabbitMQSubscriber extends ProfileSubscriber {
    constructor(connection, repository) {
        super();
        this.repository = repository;
        this.initiate(connection);
    }

    async initiate(connection) {
        if (this.channel === undefined || this.channel === null) {
            this.connection = await connection;
            this.channel = await this.connection.createChannel();   
        }
    }

    async listen(connection, queue) {
        try {
            await this.initiate(connection);
            // Declare a queue
            await this.channel.assertQueue(queue);

            // Consume messages from the queue
            this.channel.consume(queue, async (msg) => {
                if (msg !== null) {
                    console.log(`Received message (${queue}): ${msg.content.toString()}`);
                    switch (queue) {
                        case PROFILE_CREATED_EVENT:
                            await this.repository.insert(JSON.parse(msg.content.toString()));
                            break;

                        case PROFILE_UPDATED_EVENT:
                            await this.repository.update(JSON.parse(msg.content.toString()));
                            break;

                        case PROFILE_DELETED_EVENT:
                            await this.repository.delete(JSON.parse(msg.content.toString()));
                            break;
                    }
                    // Acknowledge message
                    this.channel.ack(msg);
                }
            });
        } catch (error) {
            console.error(`Error occurred while consuming event (${queue}): ${error}`);
        }
    }

    async run(connection) {
        this.onProfileCreated(connection);
        this.onProfileUpdated(connection);
        this.onProfileDeleted(connection);
    }



    async onProfileCreated(connection) {
        try {
            this.listen(connection, PROFILE_CREATED_EVENT);
        } catch (error) {
            console.error('Error occurred while consuming event (%s): %s', this.onProfileCreated.name, error);
        }
    }

    async onProfileUpdated(connection) {
        try {
            this.listen(connection, PROFILE_UPDATED_EVENT);
        } catch (error) {
            console.error('Error occurred while consuming event (%s): %s', this.onProfileUpdated.name, error);
        }
    }

    async onProfileDeleted(connection) {
        try {
            this.listen(connection, PROFILE_DELETED_EVENT);
        } catch (error) {
            console.error('Error occurred while consuming event (%s): %s', this.onProfileDeleted.name, error);
        }
    }
}

module.exports = {
    ProfileRabbitMQSubscriber
};