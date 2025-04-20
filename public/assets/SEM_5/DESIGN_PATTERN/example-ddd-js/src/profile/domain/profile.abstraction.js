/**
 * Profile Service Interface
 * @interface
 */
class ProfileServiceInterface {
    /**
     * list all profiles
     * @abstract
     */
    list(filteredBy, sortedBy) {}

    /**
     * get profile by id
     * @abstract
     */
    get(id) {}

    /**
     * add profile
     * @abstract
     */
    add(profile) {}

    /**
     * edit profile
     * @abstract
     */
    edit(profile) {}

    /**
     * remove profile
     * @abstract
     */
    remove(profile) {}
}

module.exports = {
    ProfileServiceInterface
};