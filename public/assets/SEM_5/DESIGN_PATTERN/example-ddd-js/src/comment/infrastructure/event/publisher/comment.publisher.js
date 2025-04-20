/**
 * Comment Publisher Interface
 * @interface
 */
class CommentPublisher {
    /**
     * publish
     * @abstract
     */
    publish(topic, event) {}
}


module.exports = {
    CommentPublisher
};