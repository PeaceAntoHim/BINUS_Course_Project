const { CommentQueryInterface } = require('./comment.abstraction');

class CommentQuery extends CommentQueryInterface {
    constructor(commentService, commentServiceFallback) {
        super();
        this.service = commentService;
        this.fallbackService = commentServiceFallback;
    }

    async list(userId, profileId, filteredBy, sortedBy) {
        let comments = await this.service.list(userId, profileId, filteredBy, sortedBy);
        if (comments === null || comments === undefined || comments.length === 0) {
            comments = await this.fallbackService.list(userId, profileId, filteredBy, sortedBy);

            if (comments !== null && comments !== undefined && comments.length !== 0) {
                comments.forEach(async (comment) => {
                    await this.service.add(comment);
                });
            }
        }
        return comments
    }

    async get(userId, profileId, commentId) {
        let comment = await this.service.get(userId, profileId, commentId);
        if (comment === null || comment === undefined) {
            comment = await this.fallbackService.get(userId, profileId, commentId);

            if (comment !== null && comment !== undefined) {
                await this.service.add(comment);
            }
        }
        return comment
    }
}

module.exports = {
    CommentQuery
};