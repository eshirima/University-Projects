//
//  User.swift
//  Capstone Test
//
//  Created by Emil Shirima on 2/15/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

import UIKit
import RealmSwift

class User: Object
{
    dynamic var userName: String = String()
    dynamic var passWord: String = String()
    
    func saveNewUser(newUser: User)
    {
        let realmObject = try! Realm()
        try! realmObject.write({ () -> Void in
            realmObject.add(newUser)
            print("The new user was successfully added")
        })
    }
    
    func confirmUserExistence(userInfo: User)->Bool
    {
        let realmObject = try! Realm()
        let sample = realmObject.objects(User).filter("userName = 'userInfo.userName'")
        print("User Results are: \(sample.count)")
        return sample.count > 1 ? true : false
    }
    
    func printUsers()->[User]
    {
        print("The print function was called succesffully")
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