






#include "Reply.hpp"
#include "User.hpp"
#include "vector.hpp"
#include "Stack.hpp"
#include <iostream>
using namespace std;

Reply::Reply() : content(""), author(""), parentReply(nullptr) {}

Reply::Reply(const std::string& content, const std::string& author, Reply* parent)

    : content(content), author(author), parentReply(parent) {}

// Copy constructor
Reply::Reply(const Reply& other)
    : content(other.content), author(other.author), parentReply(other.parentReply) {}

std::string Reply::getContent() const {
    return content;
}

std:: string Reply::getAuthor() const {
    return author;
}

Reply* Reply::getParentReply() const {
    return parentReply;
}


std::string Reply::quoteReplyChain() const {
    std::string chain;
    const Reply* current = this;
    while (current) {
        chain = current->content + "\n" + chain; // Prepend current content
        current = current->parentReply;         // Move to parent reply
    }
    return chain;
}














/*
std::string Reply::quoteReplyChain() const {
    if (!parentReply) {
        return content; // If no parent, return current content
    }
    return parentReply->quoteReplyChain() + "\n" + content; // Recursively quote the chain
}
*/




















/*


std::string Reply::quoteReplyChain() const {
    Stack<const Reply*> replyStack;  // Custom Stack to simulate recursion
    replyStack.push(this);

    std::string dialogue;
    while (!replyStack.empty()) {
        const Reply* current = replyStack.top();
        replyStack.pop();

        // Calculate indentation depth based on the parent reply
        int depth = 0;
        const Reply* parent = current->getParentReply();
        while (parent) {
            ++depth;
            parent = parent->getParentReply();
        }

        // Format the dialogue with user and reply content
        dialogue += std::string(depth * 4, ' ');  // Indentation
        dialogue += "[" + current->getAuthor()->getUsername() + "]: ";
        dialogue += "\"" + current->getContent() + "\"\n";

        // Push replies onto the stack in reverse order
        for (int i = current->getReplies().size() - 1; i >= 0; --i) {
            replyStack.push(current->getReplies()[i]);
        }
    }

    return dialogue;
}

























/*



std::string Reply::quoteReplyChain() const {
    Stack<const Reply*> replyStack;  // Use custom Stack
    replyStack.push(this);

    std::string quoteChain;

    while (!replyStack.empty()) {
        const Reply* current = replyStack.top();
        replyStack.pop();

        int depth = 0;
        const Reply* parent = current->getParentReply();
        while (parent) {
            ++depth;
            parent = parent->getParentReply();
        }

        // Indent based on depth
        quoteChain += std::string(depth * 4, ' ') + "Reply: \"" + current->getContent() + "\"\n";

        // Push replies onto the stack in reverse order
        for (int i = current->getReplies().size() - 1; i >= 0; --i) {
            replyStack.push(current->getReplies()[i]);
        }
    }

    return quoteChain;
}
































#pragma once
#include <string>
#include "vector.hpp"
#include "Stack.hpp"


// Reply.cpp
#include "Reply.hpp"

#include <iostream>
using namespace std;
// Reply.cpp

Reply::Reply(const std::string& content, User* author, Reply* parent)
    : content(content), author(author), parentReply(parent) {}

std::string Reply::getContent() const {
    return content;
}

User* Reply::getAuthor() const {
    return author;
}

Reply* Reply::getParentReply() const {
    return parentReply;
}

void Reply::addReply(Reply* reply) {
    replies.push_back(reply);
}

const std::vector<Reply*>& Reply::getReplies() const {
    return replies;
}
/*
std::string Reply::quoteReplyChain() const {
    std::stack<const Reply*> replyStack;
    replyStack.push(this); // Start with the current reply.

    std::string quoteChain;
    while (!replyStack.empty()) {
        const Reply* current = replyStack.top();
        replyStack.pop();

        // Add the current reply's content, prefixed with "> ".
        quoteChain += "> " + current->getContent() + "\n";

        // Push nested replies onto the stack in reverse order.
        for (size_t i = 0; i < current->getReplies().size(); ++i) {
            replyStack.push(current->getReplies()[current->getReplies().size() - 1 - i]);
        }
    }

    return quoteChain; // Return the full chain of quotes.
}


*/










/*

std::string Reply::quoteReplyChain() const {
    std::stack<const Reply*> replyStack;
    replyStack.push(this); // Start with the current reply.

    std::string quoteChain;
    while (!replyStack.empty()) {
        const Reply* current = replyStack.top();
        replyStack.pop();

        // Indent based on nesting level
        int depth = 0;
        const Reply* parent = current->getParentReply();
        while (parent) {
            ++depth;
            parent = parent->getParentReply();
        }

        // Add the current reply's content, prefixed with depth-based indentation
        quoteChain += std::string(depth * 4, ' ') + "Reply by " + current->getAuthor()->getUsername() + ": \"" + current->getContent() + "\"\n";

        // Push nested replies onto the stack in reverse order
        for (size_t i = 0; i < current->getReplies().size(); ++i) {
            replyStack.push(current->getReplies()[current->getReplies().size() - 1 - i]);
        }
    }

    return quoteChain; // Return the full chain of quotes.
}




*/







