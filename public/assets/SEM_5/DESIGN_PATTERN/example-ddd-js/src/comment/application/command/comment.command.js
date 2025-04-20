const { CommentCommandInterface } = require('./comment.abstraction');

class CommentCommand extends CommentCommandInterface {
    constructor(commentService) {
        super();
        this.service = commentService;
    }

    async add(comment) {
        return await this.service.add(comment);
    }

    async edit(comment) {
        return await this.service.edit(comment);
    }

    async remove(comment) {
        return await this.service.remove(comment);
    }

    // TODO: this should be commentId only
    async like(userId, profileId, commentId) {
        const comment = await this.service.get(userId, profileId, commentId);
        comment.likes = comment.likes + 1;
        return await this.service.edit(comment);
    }

    // TODO: this should be commentId only
    async dislike(userId, profileId, commentId) {
        const comment = await this.service.get(userId, profileId, commentId);
        comment.likes = comment.likes - 1
        return await this.service.edit(comment);
    }
}

module.exports = {
    CommentCommand
};