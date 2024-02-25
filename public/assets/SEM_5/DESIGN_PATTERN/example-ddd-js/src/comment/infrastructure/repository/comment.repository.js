/**
 * Comment Repository Interface
 * @interface
 */
class CommentRepository {
    /**
     * find all comment by userId
     * @abstract
     */
    findAll(userId, profileId, filteredBy, sortedBy) {}

    /**
     * get comment by userId and commentId
     * @abstract
     */
    find(userId, profileId, commentId) {}

    /**
     * insert comment
     * @abstract
     */
    insert(comment) {}

    /**
     * update comment
     * @abstract
     */
    update(comment) {}

    /**
     * delete comment
     * @abstract
     */
    delete(comment) {}
}


module.exports = {
    CommentRepository
};