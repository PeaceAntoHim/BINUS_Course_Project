const { ERR_NOT_FOUND, CATEGORY_ALL, SORTED_BY_RECENT } = require('../constant/profile.constant');
const { ProfileEndpointInterface } = require('./profile.abstraction');
const jwt = require('jsonwebtoken');

class ProfileEndpoint extends ProfileEndpointInterface {
    constructor(command, query, router) {
        super();
        this.query = query;
        this.command = command;
        this.router = router;
    }
    
    registerRoute() {
        this.router.post('profiles', this.add);
        this.router.put('profiles/:id', this.edit);
        this.router.delete('profiles/:id', this.delete);
        this.router.post('profiles/:id/vote', this.vote);
        this.router.post('profiles/:id/unvote', this.unvote);
        this.router.get('profiles', this.list);
        this.router.get('profiles/:id', this.get);
    }

    // TODO: Should be refactor to middleware
    getUserId(userToken) {
        try {
            const userTokenEncoded = userToken;
            const userTokenDecoded = jwt.verify(userTokenEncoded, 'jwt-secret-token');
            return userTokenDecoded.userId;
        } catch (error) {
            console.error(`error verifying jwt: ${error}`);
            throw new Error(`error verifying jwt: ${error}`);
        }
    }

    async add(req, res) {
        const { profileNew } = req.body;
        const userId = this.getUserId(req.headers['authorization']);
        try {
            let addedProfile = {};
            addedProfile.userId = userId;
            addedProfile.name = profileNew.name;
            addedProfile.description = profileNew.description;
            addedProfile.mbti = profileNew.mbti;
            addedProfile.enneagram = profileNew.enneagram;
            addedProfile.variant = profileNew.variant;
            addedProfile.tritype = profileNew.tritype;
            addedProfile.socionics = profileNew.socionics;
            addedProfile.sloan = profileNew.sloan;
            addedProfile.psyche = profileNew.psyche;
            addedProfile.image = profileNew.image;
            
            const profile = await this.command.add(addedProfile);
            res.json(profile);
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
        const { profileNew } = req.body;
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.id;
        try {
            let editedProfile = {};
            editedProfile.id = profileId;
            editedProfile.userId = userId;
            editedProfile.name = profileNew.name;
            editedProfile.description = profileNew.description;
            editedProfile.mbti = profileNew.mbti;
            editedProfile.enneagram = profileNew.enneagram;
            editedProfile.variant = profileNew.variant;
            editedProfile.tritype = profileNew.tritype;
            editedProfile.socionics = profileNew.socionics;
            editedProfile.sloan = profileNew.sloan;
            editedProfile.psyche = profileNew.psyche;
            editedProfile.image = profileNew.image;
            
            const profile = await this.command.edit(editedProfile);
            res.json(profile);
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
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.id;
        try {
            let deletedProfile = {};
            deletedProfile.id = profileId;
            deletedProfile.userId = userId;
            
            const profile = await this.command.remove(deletedProfile);
            res.json(profile);
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

    async vote(req, res) {
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.id;
        const { newVote } = req.body;
        try {
            const profile = await this.command.vote(userId, profileId, newVote.vote, newVote.category);
            res.json(profile);
        } catch (error) {
            console.error(`error on ${this.vote.name}: ${error}`);
            switch (error.msg) {
                case ERR_NOT_FOUND:
                    return res.status(404).json({ error: 'not found' });
                
                default:
                    res.status(500).json({ error: 'Internal server error' });
            }
        }
    }

    async unvote(req, res) {
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.id;
        const { newVote } = req.body;
        try {
            const profile = await this.command.unvote(userId, profileId, newVote.vote, newVote.category);
            res.json(profile);
        } catch (error) {
            console.error(`error on ${this.unvote.name}: ${error}`);
            switch (error.msg) {
                case ERR_NOT_FOUND:
                    return res.status(404).json({ error: 'not found' });
                
                default:
                    res.status(500).json({ error: 'Internal server error' });
            }
        }
    }

    async list(req, res) {
        const filteredBy = req.query.category;
        const sortedBy = req.query.sort;
        try {
            if (filteredBy === undefined || filteredBy === null) {
                filteredBy = CATEGORY_ALL;
            }
            if (sortedBy === undefined || sortedBy === null) {
                sortedBy = SORTED_BY_RECENT;
            }
            const profiles = await this.query.list(filteredBy, sortedBy);
            res.json(profiles);
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
        const userId = this.getUserId(req.headers['authorization']);
        const profileId = req.params.id;
        try {
            const profile = await this.query.get(profileId);
            res.json(profile);
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
    ProfileEndpoint
};
