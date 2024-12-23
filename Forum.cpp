#include "Forum.hpp"
#include <iostream>

Forum::Forum() : postCounter(1) {}

bool Forum::registerUser(const std::string& username, const std::string& password) {
    if (username.empty()) {
        std::cerr << "Error: Username cannot be empty!\n";
        return false;
    }
    if (users.find(username) != users.end()) {
        std::cerr << "Error: User '" << username << "' already exists.\n";
        return false;
    }
    if (password.empty()) {
        std::cerr << "Error: Password cannot be empty!\n";
        return false;
    }
    users[username] = User(username, password);
  
    return true;
}

bool Forum::loginUser(const std::string& username, const std::string& password) {
    if (!userExists(username)) {
        std::cerr << "Error: User '" << username << "' does not exist. Please register first.\n";
        return false;
    }
    if (users[username].validateLogin(password)) {
       
        return true;
    } else {
        std::cerr << "Error: Incorrect password for user '" << username << "'.\n";
        return false;
    }
}

bool Forum::createPost(const std::string& username, const std::string& content) {
    if (!userExists(username)) {
        std::cerr << "Error: User '" << username << "' does not exist. Please register first.\n";
        return false;
    }
    if (content.empty()) {
        std::cerr << "Error: Post content cannot be empty.\n";
        return false;
    }
    if (users[username].createPost(postCounter,username ,content)) {
        posts[postCounter] = Post(postCounter, username, content);
        std::cout << "Post created successfully with ID: " << postCounter << "\n";
        postCounter++;
        return true;
    }
    return false;
}


bool Forum::userExists(const std::string& username) const {
    return users.find(username) != users.end();
    
}

void Forum::displayMyPosts(const std::string& username) const {
    if (!userExists(username)) {
        std::cerr << "Error: User '" << username << "' does not exist.\n";
        return;
    }
    users.at(username).displayPosts();
}
void Forum::displayMyReplies(const std::string& username) const {
    if (!userExists(username)) {
        std::cerr << "Error: User '" << username << "' does not exist.\n";
        return;
    }
    users.at(username).displayReplies();
}

void Forum::displayAllUsers() const {
    if (users.empty()) {
        std::cout << "No users registered in the forum yet.\n";
        return;
    }
    std::cout << "List of registered users:\n";
    for (const auto& user : users) {
        std::cout << "- " << user.first << "\n";
    }
}




void Forum::replyToPost(int postId, const std::string& username, const Reply& reply) {
    if (posts.find(postId) != posts.end() && userExists(username)) {
        posts[postId].addReply(reply);
        users[username].addReply(reply);
    }
    else {
        std::cout << "Post ID or User Name not found.\n";
    }
}

void Forum::displayAllPosts() const {
    if (posts.empty()) {
        std::cout << "No posts are available.\n";
        return;
    }

    for (auto const& post : posts) {
        std::cout << "Post ID: " << post.first
            << " /n Author: " << post.second.getAuthor()
            << " /n Content: " << post.second.getContent() << "\n\n";
    }
}



void Forum::quoteReply(int postId, int replyIndex) const {
    auto postIt = posts.find(postId);
    if (postIt == posts.end()) {
        std::cerr << "Error: Post ID not found.\n";
        return;
    }

    Stack<Reply> tempStack = postIt->second.replies;
    Stack<Reply> reverseStack;

    // Reverse the stack to access replies in order
    while (!tempStack.empty()) {
        reverseStack.push(tempStack.top());
        tempStack.pop();
    }

    int currentIndex = 0;
    while (!reverseStack.empty()) {
        const Reply& reply = reverseStack.top();
        if (currentIndex == replyIndex) {
            std::cout << "Quoted Reply Chain:\n";
            std::cout << reply.quoteReplyChain() << "\n";
            return;
        }
        reverseStack.pop();
        currentIndex++;
    }

    std::cerr << "Error: Reply index out of range.\n";
}




















/*


void Forum::replyToPost(int postId, const std::string& username, const std::string& replyContent) {
    if (posts.find(postId) != posts.end() && userExists(username)) {
        posts[postId].addReply(replyContent);
        std::cout << "Reply added to Post " << postId << " by " << username << "\n";
    }
        else {
            std::cout << "Post ID or User Name not found.\n";
        }
    }





/*

void quoteReplyChain(int postID) {
    if (posts.find(postID) == posts.end()) {
        std::cout << "Post not found!\n";
        return;
    }
    std::stack<Post> replyStack;
    Post* current = &posts[postID];

    // Traverse reply chain
    while (!current->replies.empty()) {
        replyStack.push(*current);
        current = &current->replies.back();
    }
    replyStack.push(*current);

    // Print quoted chain
    while (!replyStack.empty()) {
        Post top = replyStack.top();
        replyStack.pop();
        std::cout << "Author: " << top.authorID << "\nContent: " << top.content << "\n\n";
    }
}*/