/**
 * Profile Query Interface
 * @interface
 */
class ProfileQueryInterface {
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
}

module.exports = {
    ProfileQueryInterface
};