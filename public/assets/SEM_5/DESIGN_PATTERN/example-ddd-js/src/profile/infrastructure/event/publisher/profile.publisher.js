/**
 * Profile Publisher Interface
 * @interface
 */
class ProfilePublisher {
    /**
     * publish
     * @abstract
     */
    publish(topic, event) {}
}


module.exports = {
    ProfilePublisher
};