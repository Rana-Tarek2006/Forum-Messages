#include "Post.hpp"
#include"Reply.hpp"


using namespace std;
Post::Post() : PostID(0), PostContent("") , author("") {}


Post::Post(int id, const std::string& author, const std::string& content)
    : PostID(id), author(author), PostContent(content) {
  
}

Post::Post(const Post& other)
    : PostID(other.PostID), PostContent(other.PostContent), author(other.author) {

}

Post& Post::operator=(const Post& other) {
    if (this != &other) {
        PostID = other.PostID;
        PostContent = other.PostContent;
        author = other.author;
        replies = other.replies;
      
    }
    return *this;
}

void Post::addReply(const Reply& reply) {
   
    replies.push(Reply(reply));
}

void Post:: viewRepliesChain() const {
    if (replies.empty()) {
        std::cout << "No replies yet for this post.\n";
        return;
    }

    
    std::cout << "=== Forum Conversation ===" << std::endl;
    std::cout << "[" << author << "]: \"" << PostContent << "\"" << std::endl;

    
    Stack<Reply> tempStack = replies;
    Stack<Reply> orderedStack;

   
    while (!tempStack.empty()) {
        orderedStack.push(tempStack.top());
        tempStack.pop();
    }

    
    while (!orderedStack.empty()) {
        const Reply& current = orderedStack.top();
        const Reply* currentPtr = &current;
        
        while (currentPtr) {
            std::cout << "    " << "[" << currentPtr->getAuthor() << "]: \""
                << currentPtr->getContent() << "\"" << std::endl;
            currentPtr = currentPtr->getParentReply(); 
        }
        orderedStack.pop();
    }
}


std::string Post::getContent() const {
    return PostContent;
}

std::string Post::getAuthor() const {
    return author;
}

int Post::getPostID() const {
    return PostID;
}