/**
 * Profile Command Interface
 * @interface
 */
class ProfileCommandInterface {
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

    /**
     * votes profile
     * @abstract
     */
    vote(userId, profileId, vote) {}

    /**
     * unvotes profile
     * @abstract
     */
    unvote(userId, profileId, vote) {}
}

module.exports = {
    ProfileCommandInterface
};