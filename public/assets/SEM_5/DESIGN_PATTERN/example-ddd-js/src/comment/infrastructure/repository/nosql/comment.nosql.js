const { CommentRepository } = require("../comment.repository");
const { COMMENT_MONGODB_COLLECTION_NAME } = require("../../../constant/comment.constant");
const { SORTED_BY_LIKE, SORTED_BY_RECENT, CATEGORY_ALL } = require('../../../constant/comment.constant');
const { v4: uuidv4 } = require('uuid');

class CommentNoSQLRepository extends CommentRepository {
    constructor(mongoDB) {
        super();
        this.initiate(mongoDB);
    }

    async initiate(mongoDB) {
        this.db = await mongoDB;
        this.collection = this.db.collection(COMMENT_MONGODB_COLLECTION_NAME);
    }
    
    async findAll(userId, profileId, filteredBy, sortedBy) {
        if (filteredBy === CATEGORY_ALL) {
            if (sortedBy === SORTED_BY_RECENT) {
                return await this.collection.find({ userId: userId, profileId: profileId, deletedAt: null })
                .sort({ createdAt: -1 })
                .toArray();
            }
            return await this.collection.find({ userId: userId, profileId: profileId, deletedAt: null })
            .sort({ likes: -1 })
            .toArray();
        }
        if (sortedBy === SORTED_BY_RECENT) {
            return await this.collection.find({ userId: userId, profileId: profileId, deletedAt: null, category: filteredBy })
            .sort({ createdAt: -1 })
            .toArray();
        }
        return await this.collection.find({ userId: userId, profileId: profileId, deletedAt: null, category: filteredBy })
        .sort({ likes: -1 })
        .toArray();
    }

    async findById(userId, profileId, commentId) {
        return await this.collection.findOne({ userId: userId, profileId: profileId , id: commentId, deletedAt: null });
    }

    async insert(comment) {
        comment.id = uuidv4();
        comment.createdAt = Date.now();
        if (comment.likes === undefined || comment.likes === null) {
            comment.likes = 0;
        }
        await this.collection.insertOne(comment);
        return comment;
    }

    async update(comment) {
        comment.updatedAt = Date.now();
        await this.collection.updateOne(
            { id: comment.id },
            { $set: comment }
        );
        return comment;
    }

    async delete(comment) {
        comment.deletedAt = Date.now();
        await this.collection.updateOne(
            { id: comment.id },
            { $set: comment }
        );
        return comment;
    }
}

module.exports = {
    CommentNoSQLRepository
};