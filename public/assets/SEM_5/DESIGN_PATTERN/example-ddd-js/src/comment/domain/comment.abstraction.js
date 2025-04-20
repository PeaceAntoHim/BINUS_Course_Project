/**
 * Comment Service Interface
 * @interface
 */
class CommentServiceInterface {
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

    /**
     * add comment
     * @abstract
     */
    add(comment) {}

    /**
     * edit comment
     * @abstract
     */
    edit(comment) {}

    /**
     * remove comment
     * @abstract
     */
    remove(comment) {}
}

module.exports = {
    CommentServiceInterface
};