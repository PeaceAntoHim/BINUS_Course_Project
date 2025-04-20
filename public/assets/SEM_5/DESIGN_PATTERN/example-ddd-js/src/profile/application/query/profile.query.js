const { ProfileQueryInterface } = require('./profile.abstraction');

class ProfileQuery extends ProfileQueryInterface {
    constructor(commentService, commentServiceFallback) {
        super();
        this.service = commentService;
        this.fallbackService = commentServiceFallback;
    }

    async list(filteredBy, sortedBy) {
        let profiles = await this.service.list(filteredBy, sortedBy);
        if (profiles === null || profiles === undefined || profiles.length === 0) {
            profiles = await this.fallbackService.list(filteredBy, sortedBy);

            if (profiles !== null && profiles !== undefined && profiles.length !== 0) {
                profiles.forEach(async (profile) => {
                    await this.service.add(profile);
                });
            }
        }
        return profiles
    }

    async get(id) {
        let profile = await this.service.get(id);
        if (profile === null || profile === undefined) {
            profile = await this.fallbackService.get(id);

            if (profile !== null && profile !== undefined) {
                await this.service.add(profile);
            }
        }
        return profile
    }
}

module.exports = {
    ProfileQuery
};