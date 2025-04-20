const { ProfileRepository } = require("../profile.repository");
const { PROFILE_MONGODB_COLLECTION_NAME } = require("../../../constant/profile.constant");
const { 
    SORTED_BY_VOTE, 
    SORTED_BY_RECENT, 
    CATEGORY_ALL,
    DATABASE_PROPERTY_MAP,
} = require('../../../constant/profile.constant');
const { v4: uuidv4 } = require('uuid');

class ProfileNoSQLRepository extends ProfileRepository {
    constructor(mongoDB) {
        super();
        this.initiate(mongoDB);
    }

    async initiate(mongoDB) {
        this.db = await mongoDB;
        this.collection = this.db.collection(PROFILE_MONGODB_COLLECTION_NAME);
    }
    
    async findAll(filteredBy, sortedBy) {
        if (filteredBy === CATEGORY_ALL) {
            if (sortedBy === SORTED_BY_RECENT) {
                return await this.collection.find({deletedAt: null })
                .sort({ createdAt: -1 })
                .toArray();
            }
            return await this.collection.find({deletedAt: null })
            .sort({ likes: -1 })
            .toArray();
        }
        if (sortedBy === SORTED_BY_RECENT) {
            return await this.collection.find({deletedAt: null, category: filteredBy })
            .sort({ createdAt: -1 })
            .toArray();
        }
        return await this.collection.find({deletedAt: null, category: filteredBy })
        .sort({ likes: -1 })
        .toArray();
    }

    async findById(id) {
        return await this.collection.findOne({id: id, deletedAt: null });
    }

    async insert(profile) {
        profile.id = uuidv4();
        profile.createdAt = Date.now();
        if (profile.likes === undefined || profile.likes === null) {
            profile.likes = 0;
        }
        await this.collection.insertOne(profile);
        return profile;
    }

    async update(profile) {
        profile.updatedAt = Date.now();
        await this.collection.updateOne(
            { id: profile.id },
            { $set: profile }
        );
        return profile;
    }

    async delete(profile) {
        profile.deletedAt = Date.now();
        await this.collection.updateOne(
            { id: profile.id },
            { $set: profile }
        );
        return profile;
    }
}

module.exports = {
    ProfileNoSQLRepository
};