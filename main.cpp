#include <iostream>
#include "Forum.hpp"
#include"vector.hpp"
using namespace std;

int main() {
  
      
    Forum forum;
    forum.registerUser("Alice", "alice123");
    forum.registerUser("Bob", "bob123");
    forum.registerUser("Charlie", "charlie123");

    

    // Add replies to posts
    Reply reply1("Thanks for the warm welcome!", "Bob", nullptr);
    Reply reply2("I love this community already.", "Charlie", nullptr);
    Reply reply3("Great to hear, Bob!", "Alice", &reply1);

         // Reply to post 1 by Bob
  
   
    std::string currentUsername;
    bool isLoggedIn = false;

    std::cout << "Welcome to the Forum System!\n";

    while (true) {
        int initialChoice;

        std::cout << "\nMain Menu:\n"
            << "1. Register\n"
            << "2. Login\n"
            << "3. Exit\n"
            << "Enter your choice: ";
        std::cin >> initialChoice;

        if (initialChoice == 1) {
            // Register user
            std::string username, password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            if (forum.registerUser(username, password)) {
                std::cout << "User registered successfully.\n";
            }
        }
        else if (initialChoice == 2) {
            // Login user
            std::string username, password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            if (forum.loginUser(username, password)) {
                std::cout << "Login successful for user '" << username << "'.\n";
                currentUsername = username;
                isLoggedIn = true;
                break; // Exit the loop after successful login
            }
        }
        else if (initialChoice == 3) {
            std::cout << "Exiting Forum System. Goodbye!\n";
            return 0;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    // After login, user can perform additional actions
    while (isLoggedIn) {
        int choice;

        std::cout << "\nUser Menu:\n"
            << "1. Create Post\n"
            << "2. Reply to Post\n"
            << "3. View My Posts\n"
            << "4. Display All Users\n"
            << "5. Logout\n"
            << "6. View My Replies\n"
            << "7. Display All Posts\n"
            << "8. Quote a Reply\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Create post
            std::string content;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore leftover newline
            std::cout << "\nEnter post content: ";
            std::getline(std::cin, content);

            if (forum.createPost(currentUsername, content)) {
                std::cout << "Post created successfully.\n";
            }
            break;
        }
        case 2: {
            // Reply to post
            int postId;
            std::string replyContent;
            std::cout << "\nEnter Post ID to reply to: ";
            std::cin >> postId;
            std::cin.ignore();
            std::cout << "Enter reply content: ";
            std::getline(std::cin, replyContent);

            Reply reply(replyContent, currentUsername, nullptr);
            forum.replyToPost(postId, currentUsername, reply);
            break;
        }
        case 3: {
            // View user's posts
            forum.displayMyPosts(currentUsername);
            break;
        }
        case 4: {
            // Display all users
            forum.displayAllUsers();
            break;
        }
        case 5: {
            // Logout
            std::cout << "\nLogged out successfully.\n";
            isLoggedIn = false;
            break;
        }
        case 6: {
            // View user's replies
            forum.displayMyReplies(currentUsername);
            break;
        }
        case 7: {
            // Display all posts in the forum
            forum.displayAllPosts();
            break;
        }
        case 8: {
            // Quote a reply
            int postId, replyIndex;
            std::cout << "Enter Post ID: ";
            std::cin >> postId;
            std::cout << "Enter Reply Index: ";
            std::cin >> replyIndex;

            forum.quoteReply(postId, replyIndex);
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}



    
