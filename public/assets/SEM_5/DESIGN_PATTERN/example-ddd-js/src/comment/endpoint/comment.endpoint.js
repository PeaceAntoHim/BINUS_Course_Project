const { ERR_NOT_FOUND, CATEGORY_ALL, SORTED_BY_RECENT } = require('../constant/comment.constant');
const { CommentEndpointInterface } = require('./comment.abstraction');
const jwt = require('jsonwebtoken');

class CommentEndpoint extends CommentEndpointInterface {
    constructor(command, query, router) {
        super();
        this.query = query;
        this.command = command;
        this.router = router;
    }
    
    registerRoute() {
        this.router.post('profiles/:profileId/comments', this.add);
        this.router.put('profiles/:profileId/comments/:commentId', this.edit);
        this.router.delete('profiles/:profileId/comments/:commentId', this.delete);
        this.router.post('profiles/:profileId/comments/:commentId/like', this.like);
        this.router.post('profiles/:profileId/comments/:commentId/dislike', this.dislike);
        this.router.get('profiles/:profileId/comments', this.list);
        this.router.get('profiles/:profileId/comments/:commentId', this.get);
    }

    // TODO: Should be refactor to middleware
    getUserId(userToken) {
        const userTokenEncoded = userToken;
        const userTokenDecoded = jwt.verify(userTokenEncoded, 'jwt-secret-token');
        return userTokenDecoded.userId;
    }

    async add(req, res) {
        const { commentNew } = req.body;
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.profileId;
        try {
            let addedComment = {};
            addedComment.comment = commentNew.comment;
            addedComment.userId = userId;
            addedComment.profileId = profileId;
            
            const comment = await this.command.add(addedComment);
            res.json(comment);
        } catch (error) {
            console.error(`error on ${this.add.name}: ${error}`);
            switch (error.msg) {
                case ERR_NOT_FOUND:
                    return res.status(404).json({ error: 'not found' });
                
                default:
                    res.status(500).json({ error: 'Internal server error' });
            }
        }
    }

    async edit(req, res) {
        const { commentNew } = req.body;
        const commentId = req.params.commentId;
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.profileId;
        try {
            let editedComment = {};
            editedComment.id = commentId;
            editedComment.comment = commentNew.comment;
            editedComment.userId = userId;
            editedComment.profileId = profileId;
            
            const comment = await this.command.edit(editedComment);
            res.json(comment);
        } catch (error) {
            console.error(`error on ${this.edit.name}: ${error}`);
            switch (error.msg) {
                case ERR_NOT_FOUND:
                    return res.status(404).json({ error: 'not found' });
                
                default:
                    res.status(500).json({ error: 'Internal server error' });
            }
        }
    }

    async remove(req, res) {
        const commentId = req.params.commentId;
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.profileId;
        try {
            let deletedComment = {};
            deletedComment.id = commentId;
            deletedComment.userId = userId;
            deletedComment.profileId = profileId;
            
            const comment = await this.command.remove(deletedComment);
            res.json(comment);
        } catch (error) {
            console.error(`error on ${this.remove.name}: ${error}`);
            switch (error.msg) {
                case ERR_NOT_FOUND:
                    return res.status(404).json({ error: 'not found' });
                
                default:
                    res.status(500).json({ error: 'Internal server error' });
            }
        }
    }

    async like(req, res) {
        const commentId = req.params.commentId;
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.profileId;
        try {
            const comment = await this.command.like(userId, profileId, commentId);
            res.json(comment);
        } catch (error) {
            console.error(`error on ${this.like.name}: ${error}`);
            switch (error.msg) {
                case ERR_NOT_FOUND:
                    return res.status(404).json({ error: 'not found' });
                
                default:
                    res.status(500).json({ error: 'Internal server error' });
            }
        }
    }

    async dislike(req, res) {
        const commentId = req.params.commentId;
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.profileId;
        try {
            const comment = await this.command.dislike(userId, profileId, commentId);
            res.json(comment);
        } catch (error) {
            console.error(`error on ${this.dislike.name}: ${error}`);
            switch (error.msg) {
                case ERR_NOT_FOUND:
                    return res.status(404).json({ error: 'not found' });
                
                default:
                    res.status(500).json({ error: 'Internal server error' });
            }
        }
    }

    async list(req, res) {
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.profileId;
        const filteredBy = req.query.category;
        const sortedBy = req.query.sort;
        try {
            if (filteredBy === undefined || filteredBy === null) {
                filteredBy = CATEGORY_ALL;
            }
            if (sortedBy === undefined || sortedBy === null) {
                sortedBy = SORTED_BY_RECENT;
            }
            const comments = await this.query.list(userId, profileId, filteredBy, sortedBy);
            res.json(comments);
        } catch (error) {
            console.error(`error on ${this.list.name}: ${error}`);
            switch (error.msg) {
                case ERR_NOT_FOUND:
                    return res.status(404).json({ error: 'not found' });
                
                default:
                    res.status(500).json({ error: 'Internal server error' });
            }
        }
    }

    async get(req, res) {
        const commentId = req.params.commentId;
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.profileId;
        try {
            const comment = await this.command.get(userId, profileId, commentId);
            res.json(comment);
        } catch (error) {
            console.error(`error on ${this.get.name}: ${error}`);
            switch (error.msg) {
                case ERR_NOT_FOUND:
                    return res.status(404).json({ error: 'not found' });
                
                default:
                    res.status(500).json({ error: 'Internal server error' });
            }
        }
    }
}

module.exports = {
    CommentEndpoint
};
