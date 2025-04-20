const { ERR_BAD_REQUEST } = require('../../constant/profile.constant');
const { ProfileCommandInterface } = require('./profile.abstraction');

class ProfileCommand extends ProfileCommandInterface {
    constructor(profileService) {
        super();
        this.service = profileService;
    }

    async add(profile) {
        return await this.service.add(profile);
    }

    async edit(profile) {
        return await this.service.edit(profile);
    }

    async remove(profile) {
        return await this.service.remove(profile);
    }

    async vote(userId, profileId, vote, category) {
        const profile = await this.service.get(profileId);
        
        if (profile.votes[category] === undefined || profile.votes[category] === null) {
            profile.votes[category] = [];
        }

        if (profile.votes[category].length > 3) {
            throw new Error(ERR_BAD_REQUEST);
        }

        profile.votes[category].push({
            vote: vote,
            userId: userId,
        });
        return await this.service.edit(profile);
    }

    async unvote(userId, profileId, vote, category) {
        const profile = await this.service.get(profileId);
                
        if (profile.votes[category] === undefined || profile.votes[category] === null) {
            profile.votes[category] = [];
        }

        profile.votes[category] = profile.votes[category].filter((existingVote) => existingVote.vote !== vote || existingVote.userId !== userId);
        return await this.service.edit(profile);
    }
}

module.exports = {
    ProfileCommand
};