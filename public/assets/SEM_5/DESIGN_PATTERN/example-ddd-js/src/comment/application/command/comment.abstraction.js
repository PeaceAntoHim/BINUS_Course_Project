/**
 * Comment Command Interface
 * @interface
 */
class CommentCommandInterface {
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

    /**
     * likes comment
     * @abstract
     */
    like(userId, profileId, commentId) {}

    /**
     * dislikes comment
     * @abstract
     */
    dislike(userId, profileId, commentId) {}
}

module.exports = {
    CommentCommandInterface
};