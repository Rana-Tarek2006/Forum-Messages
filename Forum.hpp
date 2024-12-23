#pragma once
#include <string>
#include "User.hpp"
#include "Post.hpp"
#include <map>
class Forum {
public:
    std::map<std::string, User> users;
    std::map<int, Post> posts;
  

    int postCounter;


    Forum();
    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    bool createPost(const std::string& username, const std::string& postContent);
    void displayMyPosts(const std::string& username) const;
    bool userExists(const std::string& username) const;
    void displayAllUsers() const;
    void replyToPost(int postId, const std::string& username, const Reply& reply);
    void displayMyReplies(const std::string& username) const;
    void displayAllPosts() const;
    void quoteReply(int postId, int replyIndex) const;


};




