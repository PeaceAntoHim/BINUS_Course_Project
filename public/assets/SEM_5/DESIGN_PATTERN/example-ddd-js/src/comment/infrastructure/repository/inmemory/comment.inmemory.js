const { CommentRepository } = require("../comment.repository");
const { 
    COMMENT_REDIS_KEY, 
    COMMENT_REDIS_KEY_PREFIX_1, 
    COMMENT_REDIS_KEY_PREFIX_2, 
    ERR_NOT_FOUND, 
    CATEGORY_ALL,
    SORTED_BY_LIKE,
    SORTED_BY_RECENT,
} = require("../../../constant/comment.constant");

class CommentInMemoryRepository extends CommentRepository {
    constructor(redisClient) {
        super();
        this.redisClient = redisClient;
    }
    
    async findAll(userId, profileId, filteredBy, sortedBy) {
        const commentsInString = await this.redisClient.get(COMMENT_REDIS_KEY_PREFIX_1 + '.' + userId + "." + COMMENT_REDIS_KEY_PREFIX_2 + "." + profileId + "." + COMMENT_REDIS_KEY);
        let comments = JSON.parse(commentsInString);
        if (comments !== undefined && comments !== null && comments.length !== 0) {
            if (filteredBy !== CATEGORY_ALL) {
                comments = comments.filter((comment) => comment.category === filteredBy);
            }
            switch(sortedBy) {
                case SORTED_BY_LIKE:
                    comments = comments.sort((a, b) => b.likes - a.likes);
                    break;

                case SORTED_BY_RECENT:
                    comments = comments.sort((a, b) => b.createdAt - a.createdAt);
                    break;
            }
        }
        return comments;
    }

    async findById(userId, profileId, commentId) {
        const allComments = await this.findAll(userId, profileId, CATEGORY_ALL, SORTED_BY_LIKE);

        const comment = allComments.map((comment) => {
            if (comment.id === commentId) {
                return comment;
            } 
        });

        if (comment.length === 0) {
            throw new Error(ERR_NOT_FOUND);
        }
        return comment[0];
    }

    async insert(comment) {
        const key = COMMENT_REDIS_KEY_PREFIX_1 + '.' + comment.userId + "." + COMMENT_REDIS_KEY_PREFIX_2 + "." + comment.profileId + "." + COMMENT_REDIS_KEY;
        var allComments = await this.findAll(comment.userId, comment.profileId, CATEGORY_ALL, SORTED_BY_RECENT);
        if (allComments === null || allComments === undefined) {
            allComments = new Array();
        }
        if (allComments.length === 0) {
            allComments.push(comment);
        }
        await this.redisClient.set(key, JSON.stringify(allComments));
        return comment;
    }

    async update(comment) {
        const key = COMMENT_REDIS_KEY_PREFIX_1 + '.' + comment.userId + "." + COMMENT_REDIS_KEY_PREFIX_2 + "." + comment.profileId + "." + COMMENT_REDIS_KEY;
        var allComments = await this.findAll(comment.userId, comment.profileId, CATEGORY_ALL, SORTED_BY_RECENT);
        var isFound = false;
        
        if (allComments !== null && allComments !== undefined) {
            allComments = allComments.map((existingComment) => {
                if (existingComment.id === comment.id) {
                    isFound = true;
                    existingComment = comment;
                }
                return existingComment;
            });
        }
        
        if (!isFound) {
            throw new Error(ERR_NOT_FOUND);
        }
        await this.redisClient.set(key, JSON.stringify(allComments));
        return comment;
    }

    async delete(comment) {
        const key = COMMENT_REDIS_KEY_PREFIX_1 + '.' + comment.userId + "." + COMMENT_REDIS_KEY_PREFIX_2 + "." + comment.profileId + "." + COMMENT_REDIS_KEY;
        var allComments = await this.findAll(comment.userId, comment.profileId, CATEGORY_ALL, SORTED_BY_RECENT);
        var isFound = false;
        
        if (allComments !== null && allComments !== undefined) {
            allComments.forEach((existingComment) => {
                if (existingComment.id === comment.id){
                    isFound = true;
                }
            });

            allComments = allComments.filter((existingComment) => {
                return existingComment.id !== comment.id;
            });
        }

        if (!isFound) {
            throw new Error(ERR_NOT_FOUND);
        }
        
        if (allComments === null || allComments === undefined || allComments.length === 0) {
            await this.redisClient.del(key);
        } else {
            await this.redisClient.set(key, JSON.stringify(allComments));
        }
        return comment;
    }
}

module.exports = {
    CommentInMemoryRepository
};