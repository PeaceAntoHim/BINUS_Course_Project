const { ProfileRepository } = require("../profile.repository");
const { 
    PROFILE_REDIS_KEY,
    ERR_NOT_FOUND, 
    CATEGORY_ALL,
    SORTED_BY_VOTE,
    SORTED_BY_RECENT,
} = require("../../../constant/profile.constant");

class ProfileInMemoryRepository extends ProfileRepository {
    constructor(redisClient) {
        super();
        this.redisClient = redisClient;
    }
    
    async findAll(filteredBy, sortedBy) {
        const profilesInString = await this.redisClient.get(PROFILE_REDIS_KEY)
        let profiles = JSON.parse(profilesInString);
        if (profiles !== undefined && profiles !== null && profiles.length !== 0) {
            if (filteredBy !== CATEGORY_ALL) {
                profiles = profiles.filter((profile) => profile.category === filteredBy);
            }
            switch(sortedBy) {
                case SORTED_BY_VOTE:
                    profiles = profiles.sort((a, b) => b.votes - a.votes);
                    break;

                case SORTED_BY_RECENT:
                    profiles = profiles.sort((a, b) => b.createdAt - a.createdAt);
                    break;
            }
        }
        return profiles;
    }

    async findById(profileId) {
        const allProfiles = await this.findAll(CATEGORY_ALL, SORTED_BY_VOTE);

        const profile = allProfiles.map((profile) => {
            if (profile.id === profileId) {
                return profile;
            } 
        });

        if (profile.length === 0) {
            throw new Error(ERR_NOT_FOUND);
        }
        return profile[0];
    }

    async insert(profile) {
        const key = PROFILE_REDIS_KEY;
        var allProfiles = await this.findAll(CATEGORY_ALL, SORTED_BY_RECENT);
        if (allProfiles === null || allProfiles === undefined) {
            allProfiles = new Array();
        }
        if (allProfiles.length === 0) {
            allProfiles.push(profile);
        }
        await this.redisClient.set(key, JSON.stringify(allProfiles));
        return profile;
    }

    async update(profile) {
        const key = PROFILE_REDIS_KEY;
        var allProfiles = await this.findAll(CATEGORY_ALL, SORTED_BY_RECENT);
        var isFound = false;
        
        if (allProfiles !== null && allProfiles !== undefined) {
            allProfiles = allProfiles.map((existingProfile) => {
                if (existingProfile.id === profile.id) {
                    isFound = true;
                    existingProfile = profile;
                }
                return existingProfile;
            });
        }
        
        if (!isFound) {
            throw new Error(ERR_NOT_FOUND);
        }
        await this.redisClient.set(key, JSON.stringify(allProfiles));
        return profile;
    }

    async delete(profile) {
        const key = PROFILE_REDIS_KEY;
        var allProfiles = await this.findAll(CATEGORY_ALL, SORTED_BY_RECENT);
        var isFound = false;
        
        if (allProfiles !== null && allProfiles !== undefined) {
            allProfiles.forEach((existingProfile) => {
                if (existingProfile.id === profile.id){
                    isFound = true;
                }
            });

            allProfiles = allProfiles.filter((existingProfile) => {
                return existingProfile.id !== profile.id;
            });
        }

        if (!isFound) {
            throw new Error(ERR_NOT_FOUND);
        }
        
        if (allProfiles === null || allProfiles === undefined || allProfiles.length === 0) {
            await this.redisClient.del(key);
        } else {
            await this.redisClient.set(key, JSON.stringify(allProfiles));
        }
        return profile;
    }
}

module.exports = {
    ProfileInMemoryRepository
};