const { ProfileServiceInterface } = require('./profile.abstraction');
const { 
    PROFILE_CREATED_EVENT, 
    PROFILE_UPDATED_EVENT, 
    PROFILE_DELETED_EVENT, 
    PROFILE_QUEUE_NAME 
} = require('../constant/profile.constant');

class ProfileService extends ProfileServiceInterface {
    constructor(repository, publisher) {
        super();
        this.repository = repository;
        this.publisher = publisher;
    }

    async list(filteredBy, sortedBy) {
        return await this.repository.findAll(filteredBy, sortedBy);
    }

    async get(id) {
        return await this.repository.find(id);
    }

    async add(profile) {
        const addedProfile = await this.repository.insert(profile);
        await this.publisher.publish(PROFILE_CREATED_EVENT, addedProfile);
        return addedProfile;
    }

    async edit(profile) {
        const editedProfile = await this.repository.update(profile);
        await this.publisher.publish(PROFILE_UPDATED_EVENT, editedProfile);
        return editedProfile;
    }

    async remove(profile) {
        const removedProfile = await this.repository.delete(profile);
        await this.publisher.publish(PROFILE_DELETED_EVENT, removedProfile);
        return removedProfile;
    }
}

module.exports = {
    ProfileService
};