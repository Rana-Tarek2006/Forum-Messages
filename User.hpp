#pragma once
#include <string>
#include "Post.hpp"
#include "Reply.hpp"
#include "vector.hpp"


class Reply;
class Post;
class User {
private:
    std::string password;
  
public:
   vector<string> replies;
    std::string username;
   vector<Post> posts;
    User();

    User(const std::string& name, const std::string& pass);
    bool createPost(int postID,const  std::string& author,const std::string& postContent);
    void displayPosts() const;
    bool validateLogin(const std::string& inputPassword) const;
    std::string getUsername() const;
    void addReply(const Reply& reply);
    void displayReplies() const;
};