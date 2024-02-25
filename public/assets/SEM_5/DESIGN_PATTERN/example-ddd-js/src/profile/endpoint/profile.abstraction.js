/**
 * Profile Endpoint Interface
 * @interface
 */
class ProfileEndpointInterface {
    /**
     * add profile
     * @abstract
     */
    add(req, res) {}

    /**
     * edit profile
     * @abstract
     */
    edit(req, res) {}

    /**
     * remove profile
     * @abstract
     */
    remove(req, res) {}

    /**
     * likes profile
     * @abstract
     */
    vote(req, res) {}

    /**
     * dislikes profile
     * @abstract
     */
    unvote(req, res) {}

    /**
     * list all profiles
     * @abstract
     */
    list(req, res) {}

    /**
     * get profile by profileId
     * @abstract
     */
    get(req, res) {}

    /**
     * register all routes for profiles
     * @abstract
     */
    registerRoute() {}
}

module.exports = {
    ProfileEndpointInterface
};