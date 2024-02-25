const { CommentSubscriber } = require('../comment.subscriber')
const { COMMENT_CREATED_EVENT, COMMENT_UPDATED_EVENT, COMMENT_DELETED_EVENT, COMMENT_QUEUE_NAME } = require('../../../../constant/comment.constant');

class CommentRabbitMQSubscriber extends CommentSubscriber {
    constructor(connection, commentRepository) {
        super();
        this.repository = commentRepository;
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
                        case COMMENT_CREATED_EVENT:
                            await this.repository.insert(JSON.parse(msg.content.toString()));
                            break;

                        case COMMENT_UPDATED_EVENT:
                            await this.repository.update(JSON.parse(msg.content.toString()));
                            break;

                        case COMMENT_DELETED_EVENT:
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
        this.onCommentCreated(connection);
        this.onCommentUpdated(connection);
        this.onCommentDeleted(connection);
    }

    async onCommentCreated(connection) {
        try {
            this.listen(connection, COMMENT_CREATED_EVENT);
        } catch (error) {
            console.error('Error occurred while consuming event (%s): %s', this.onCommentCreated.name, error);
        }
    }

    async onCommentUpdated(connection) {
        try {
            this.listen(connection, COMMENT_UPDATED_EVENT);
        } catch (error) {
            console.error('Error occurred while consuming event (%s): %s', this.onCommentUpdated.name, error);
        }
    }

    async onCommentDeleted(connection) {
        try {
            this.listen(connection, COMMENT_DELETED_EVENT);
        } catch (error) {
            console.error('Error occurred while consuming event (%s): %s', this.onCommentDeleted.name, error);
        }
    }
}

module.exports = {
    CommentRabbitMQSubscriber
};