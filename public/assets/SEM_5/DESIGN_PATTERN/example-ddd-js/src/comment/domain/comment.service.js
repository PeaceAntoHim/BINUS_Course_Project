const { CommentServiceInterface } = require('./comment.abstraction');
const { COMMENT_CREATED_EVENT, COMMENT_UPDATED_EVENT, COMMENT_DELETED_EVENT, COMMENT_QUEUE_NAME } = require('../constant/comment.constant');

class CommentService extends CommentServiceInterface {
    constructor(commentRepository, commentPublisher) {
        super();
        this.repository = commentRepository;
        this.publisher = commentPublisher;
    }

    async list(userId, profileId, filteredBy, sortedBy) {
        return await this.repository.findAll(userId, profileId, filteredBy, sortedBy);
    }

    async get(userId, profileId, commentId) {
        return await this.repository.find(userId, profileId, commentId);
    }

    async add(comment) {
        const addedComment = await this.repository.insert(comment);
        await this.publisher.publish(COMMENT_CREATED_EVENT, addedComment);
        return addedComment;
    }

    async edit(comment) {
        const editedComment = await this.repository.update(comment);
        await this.publisher.publish(COMMENT_UPDATED_EVENT, editedComment);
        return editedComment;
    }

    async remove(comment) {
        const removedComment = await this.repository.delete(comment);
        await this.publisher.publish(COMMENT_DELETED_EVENT, removedComment);
        return removedComment;
    }
}

module.exports = {
    CommentService
};