

#pragma once
#include <string>
#include "User.hpp"    // Include User class
#include "vector.hpp"  // Custom vector class
#include "Stack.hpp"   // Custom Stack class

class Reply {
private:
    std::string content;
   std:: string author;
    Reply* parentReply;
    // Use custom vector

public:
    Reply(const std::string& content, const std::string& author, Reply* parent);
    Reply();
    Reply(const Reply& other);
    std::string getContent() const;
   std:: string getAuthor() const;
    Reply* getParentReply() const;

    // Function to print the quoted reply chain
    std::string quoteReplyChain() const;
};








/*




























#pragma once
#include <string>
#include "vector.hpp"
#include "Stack.hpp"

// Reply.h
#ifndef REPLY_H
#define REPLY_H
#include <iostream>

using namespace std;

#include "User.hpp"

class Reply {
private:
    std::string content;
    User* author;
    Reply* parentReply;
    std::vector<Reply*> replies;

public:
    Reply(const std::string& content, User* author, Reply* parent = nullptr);
    std::string getContent() const;
    User* getAuthor() const;
    Reply* getParentReply() const;
    void addReply(Reply* reply);
    const std::vector<Reply*>& getReplies() const;

    // New function to quote the reply chain
    std::string quoteReplyChain() const;
};

#endif // REPLY_H
*/