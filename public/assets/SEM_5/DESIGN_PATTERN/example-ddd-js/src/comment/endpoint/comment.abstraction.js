/**
 * Comment Endpoint Interface
 * @interface
 */
class CommentEndpointInterface {
    /**
     * add comment
     * @abstract
     */
    add(req, res) {}

    /**
     * edit comment
     * @abstract
     */
    edit(req, res) {}

    /**
     * remove comment
     * @abstract
     */
    remove(req, res) {}

    /**
     * likes comment
     * @abstract
     */
    like(req, res) {}

    /**
     * dislikes comment
     * @abstract
     */
    dislike(req, res) {}

    /**
     * list all comment by userId and profileId
     * @abstract
     */
    list(req, res) {}

    /**
     * get comment by userId and commentId
     * @abstract
     */
    get(req, res) {}

    /**
     * register all routes for comments
     * @abstract
     */
    registerRoute() {}
}

module.exports = {
    CommentEndpointInterface
};