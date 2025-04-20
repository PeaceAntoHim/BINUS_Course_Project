/**
 * Comment Query Interface
 * @interface
 */
class CommentQueryInterface {
    /**
     * list all comment by userId and profileId
     * @abstract
     */
    list(userId, profileId, filteredBy, sortedBy) {}

    /**
     * get comment by userId and commentId
     * @abstract
     */
    get(userId, profileId, commentId) {}
}

module.exports = {
    CommentQueryInterface
};