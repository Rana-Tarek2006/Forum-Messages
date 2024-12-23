#include "User.hpp"
#include <iostream>
#include"vector.hpp"
using namespace std;
User::User(const std::string& username, const std::string& pass) : username(username), password(pass) {}

User::User() : username(""), password("") {}

bool User::createPost(int postID, const std::string& author ,const std::string& content) {
    if (content.empty()) {
        std::cerr << "Error: Post content cannot be empty.\n";
        return false;
    }
    Post p(postID, username, content);
    posts.push(p);
    std::cout << "DEBUG: Post pushed to vector successfully.\n";
    return true;
}

void User::displayPosts() const {
    if (posts.empty()) {
        std::cout << username << " has no posts.\n";
        return;
    }
    std::cout << username << "'s posts:\n";
    for (int i = 0; i < posts.size(); i++) {
        std::cout << "Post ID: " << posts[i].PostID << " | Content: " << posts[i].PostContent << "\n";
        
        cout << "Viewing replies for " << username << " Post:\n";
        
        posts[i].viewRepliesChain();
    }
}

bool User::validateLogin(const std::string& inputPassword) const {
    return password == inputPassword;
}

std::string User::getUsername() const {
    return username;
}

void User::addReply(const Reply& reply) {
    replies.push(reply.getContent());
}


void User::displayReplies() const {
    if (replies.empty()) {
        std::cout << username << " has not made any replies yet.\n";
        return;
    }

    std::cout << "Replies by " << username << ":\n";
    for (int i = 0; i < replies.size(); i++) {
        std::cout << "- " << replies[i] << "\n";

       
    }
}
