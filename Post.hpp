#pragma once
#include <string>
#include"Stack.hpp"
#include"Reply.hpp"
using namespace std;


class Reply;




class Post {

public:
    int PostID;
    std::string PostContent;
    std::string author;
    Stack<Reply> replies;  

    Post();
   
    Post(int id, const std::string& author, const std::string& content);

    void addReply(const Reply& reply);
    void viewRepliesChain() const;
    std::string getContent() const;
    std::string getAuthor() const;

    int getPostID() const;

    Post(const Post& other);
    

    // Assignment Operator
    Post& operator=(const Post& other);

};