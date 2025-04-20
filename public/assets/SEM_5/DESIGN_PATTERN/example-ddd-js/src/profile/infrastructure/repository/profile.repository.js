/**
 * Profile Repository Interface
 * @interface
 */
class ProfileRepository {
    /**
     * find all profile
     * @abstract
     */
    findAll(filteredBy, sortedBy) {}

    /**
     * get profile by commentId
     * @abstract
     */
    find(profileId) {}

    /**
     * insert profile
     * @abstract
     */
    insert(profile) {}

    /**
     * update profile
     * @abstract
     */
    update(profile) {}

    /**
     * delete profile
     * @abstract
     */
    delete(profile) {}
}


module.exports = {
    ProfileRepository
};