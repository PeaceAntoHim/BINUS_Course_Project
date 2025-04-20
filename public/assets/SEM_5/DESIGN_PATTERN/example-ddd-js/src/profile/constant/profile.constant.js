const PROFILE_MONGODB_COLLECTION_NAME = 'profiles';

const PROFILE_REDIS_KEY = 'profiles';

const ERR_NOT_FOUND = "not found";
const ERR_BAD_REQUEST = "bad request";

const PROFILE_CREATED_EVENT = 'profile.created.event';
const PROFILE_UPDATED_EVENT = 'profile.updated.event';
const PROFILE_DELETED_EVENT = 'profile.deleted.event';

const PROFILE_QUEUE_NAME = 'profile.queue';

const SORTED_BY_VOTE = 'votes';
const SORTED_BY_RECENT = 'recents';

const CATEGORY_MBTI = 'MBTI';
const CATEGORY_ENNEAGRAM = 'Enneagram';
const CATEGORY_ZODIAC = 'Zodiac';
const CATEGORY_ALL = 'All';

const DATABASE_PROPERTY_MAP = new Map();
DATABASE_PROPERTY_MAP.set(CATEGORY_MBTI, 'mbti');
DATABASE_PROPERTY_MAP.set(CATEGORY_ENNEAGRAM, 'enneagram');
DATABASE_PROPERTY_MAP.set(CATEGORY_ZODIAC, 'zodiac');

module.exports = {
    PROFILE_MONGODB_COLLECTION_NAME,
    PROFILE_REDIS_KEY,
    ERR_NOT_FOUND,
    ERR_BAD_REQUEST,
    PROFILE_CREATED_EVENT,
    PROFILE_UPDATED_EVENT,
    PROFILE_DELETED_EVENT,
    PROFILE_QUEUE_NAME,
    SORTED_BY_VOTE,
    SORTED_BY_RECENT,
    CATEGORY_ALL,
    CATEGORY_ENNEAGRAM,
    CATEGORY_MBTI,
    CATEGORY_ZODIAC,
    DATABASE_PROPERTY_MAP,
};