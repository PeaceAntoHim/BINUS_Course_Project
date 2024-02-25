const COMMENT_MONGODB_COLLECTION_NAME = 'comments';

const COMMENT_REDIS_KEY = 'comments';
const COMMENT_REDIS_KEY_PREFIX_2 = 'profiles';
const COMMENT_REDIS_KEY_PREFIX_1 = 'users';

const ERR_NOT_FOUND = "not found";

const COMMENT_CREATED_EVENT = 'comment.created.event';
const COMMENT_UPDATED_EVENT = 'comment.updated.event';
const COMMENT_DELETED_EVENT = 'comment.deleted.event';

const COMMENT_QUEUE_NAME = 'comment.queue';

const SORTED_BY_LIKE = 'likes';
const SORTED_BY_RECENT = 'recents';

const CATEGORY_MBTI = 'MBTI';
const CATEGORY_ENNEAGRAM = 'Enneagram';
const CATEGORY_ZODIAC = 'Zodiac';
const CATEGORY_ALL = 'All';

module.exports = {
    COMMENT_MONGODB_COLLECTION_NAME,
    COMMENT_REDIS_KEY,
    COMMENT_REDIS_KEY_PREFIX_2,
    COMMENT_REDIS_KEY_PREFIX_1,
    ERR_NOT_FOUND,
    COMMENT_CREATED_EVENT,
    COMMENT_UPDATED_EVENT,
    COMMENT_DELETED_EVENT,
    COMMENT_QUEUE_NAME,
    SORTED_BY_LIKE,
    SORTED_BY_RECENT,
    CATEGORY_ALL,
    CATEGORY_ENNEAGRAM,
    CATEGORY_MBTI,
    CATEGORY_ZODIAC
};