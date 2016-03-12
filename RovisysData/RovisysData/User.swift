//
//  User.swift
//  RovisysData
//
//  Created by Emil Shirima on 3/9/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

import UIKit
import RealmSwift

class User: Object
{
    // MARK: Member Variables
    private dynamic var userName: String = String() // Primary Key
    private dynamic var isAdmin: Bool = false
    private dynamic var password: String = String()
    
    private var allUserProjects = List<ParentProject>()
    
    override static func primaryKey()->String
    {
        return "userName"
    }
    
    // MARK: Getters
    func getUserName()->String
    {
        return userName
    }
    
    func getPassword()->String
    {
        return password
    }
    
    func getUserAuthorisation()->Bool
    {
        return isAdmin
    }
    
    // MARK: Setters
    func setUsrName(newUserName: String) // Objective-C conflicts when setUserName is used
    {
        userName = newUserName
    }
    
    func setUserCredentials(newAdminCredentials: Bool)
    {
        isAdmin = newAdminCredentials
    }
    
    func setUserPassword(newUserPassword: String)
    {
        password = newUserPassword
    }
    
    // TODO: Store the password in the keychain
    func createNewUser(newUserName: String, newUserPassword: String, isUserAdmin: Bool)
    {
        userName = newUserName
        password = newUserPassword
        isAdmin = isUserAdmin
    }
    
    // POST: Stores the new user to Realm
    func saveNewUser(newUser: User)
    {
        let realmObject = try! Realm()
        try! realmObject.write({ () -> Void in
            realmObject.add(newUser)
            // TODO: Alert the user
            print("The new user was succesfully added")
        })
    }
    
    // POST: Searches Realm for user existence
    func doesUserExist(userInfo: User)->Bool
    {
        let searchUserPredicate: NSPredicate = NSPredicate(format: "userName = %@", userInfo.userName)
        let realmObject = try! Realm()
        let userElements = realmObject.objects(User).filter(searchUserPredicate)
        print("User Results are \(userElements.count)")
        return userElements.count > 0 ? true : false
    }
    
    // POST: Returns all the parent projects linked to the current user
    func searchForUserRelatedProjects()->Results<ParentProject>
    {
        let searchUserProjectsPredicate: NSPredicate = NSPredicate(format: "submmittedBy = %@", userName)
        let realmObject = try! Realm()
        let userProjects = realmObject.objects(ParentProject).filter(searchUserProjectsPredicate)
        return userProjects
    }
    
    // POST: Returns all the parent projects in Realm
    func getAllParentProjects()->List<ParentProject>
    {
        let userProjects = searchForUserRelatedProjects()
        allUserProjects.appendContentsOf(userProjects)
        
        return allUserProjects
    }
    
    // POST: Add a new project to the current user
    func addParentProject(currentUser: User)
    {
        allUserProjects = getAllParentProjects()
        
        let realmObject = try! Realm()
        try! realmObject.write({ () -> Void in
            realmObject.add(currentUser, update: true)
        // TODO: Alert the user
        print("User new project succesfully added")
        })
    }
    
    // MARK: For debug purposes
    // POST: Prints all the users in Realm
    func printAllUsers()->[User]
    {
        let realmObject = try! Realm()
        let allUsers = realmObject.objects(User)
        var users: [User] = [User]()
        
        if allUsers.count > 0
        {
            for thisUser in allUsers
            {
                let user = thisUser as User
                users.append(user)
            }
        }
        
        return users
    }
}