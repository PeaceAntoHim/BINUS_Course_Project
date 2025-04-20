'use strict';

const {
  commentCommand,
  commentQuery,
  profileCommand,
  profileQuery,
} = require('../dependency_injection/dependency_injection');
const { ProfileEndpoint } = require('../src/profile/endpoint/profile.endpoint');
const { CommentEndpoint } = require('../src/comment/endpoint/comment.endpoint');

const express = require('express');
const router = express.Router();

const profiles = [
  {
    "id": 1,
    "name": "A Martinez",
    "description": "Adolph Larrue Martinez III.",
    "mbti": "ISFJ",
    "enneagram": "9w3",
    "variant": "sp/so",
    "tritype": 725,
    "socionics": "SEE",
    "sloan": "RCOEN",
    "psyche": "FEVL",
    "image": "https://soulverse.boo.world/images/1.png",
  }
];

const commentEndpoint = new CommentEndpoint(commentCommand, commentQuery, router);
const profileEndpoint = new ProfileEndpoint(profileCommand, profileQuery, router);

module.exports = function() {

  router.get('/*', function(req, res, next) {
    res.render('profile_template', {
      profile: profiles[0],
    });
  });

  commentEndpoint.registerRoute();
  profileEndpoint.registerRoute();

  return router;
}

module.exports = {
  router,
};
