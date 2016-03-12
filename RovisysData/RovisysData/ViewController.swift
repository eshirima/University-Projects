//
//  ViewController.swift
//  RovisysData
//
//  Created by Emil Shirima on 3/9/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    func createNewUser(userName: String, password:String, isAdmin:Bool)->User
    {
        let userObject = User()
        userObject.createNewUser(userName, newUserPassword: password, isUserAdmin: isAdmin)
        
        if !userObject.doesUserExist(userObject)
        {
            userObject.saveNewUser(userObject)
        }
        
        return userObject
    }
    
    func createNewParentProject(projectName: String, projectOwner: String, projectSubmissionDate: NSDate, projectDescription: String)->ParentProject
    {
        let parentProjectObject = ParentProject()
        
        parentProjectObject.createParentProject(projectName, projectOwnerName: projectOwner, projectSubmissionDate: projectSubmissionDate, newProjectDescription: projectDescription)
        
        if !parentProjectObject.doesParentProjectExist(parentProjectObject)
        {
            parentProjectObject.saveNewProject(parentProjectObject)
        }
        
        return parentProjectObject
    }
    
    func linkUserToParentProject(userObject: User) // call this without calling the getAllParentProjects method right after
    {
        userObject.addParentProject(userObject)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        let firstUser = createNewUser("people@yahoo.com", password: "hello", isAdmin: false)
        let secondUser = createNewUser("ujeloduvy-0448@yopmail.com", password: "huiwi43", isAdmin: false)
        let thirdUser = createNewUser("Witim1948@einrot.com", password: "ywwrtwuwg", isAdmin: false)
        
        let firstProject = createNewParentProject("Capstone", projectOwner: firstUser.getUserName(), projectSubmissionDate: NSDate(), projectDescription: "Rovisys Expense Tracker")
        let secondProject = createNewParentProject("Site Surveying", projectOwner: firstUser.getUserName(), projectSubmissionDate: NSDate(), projectDescription: "Site survey of Aragon Electronics")
        let thirdProject = createNewParentProject("Dinner", projectOwner: firstUser.getUserName(), projectSubmissionDate: NSDate(), projectDescription: "Dining at Red Lobster")
        let fourthProject = createNewParentProject("Furniture", projectOwner: firstUser.getUserName(), projectSubmissionDate: NSDate(), projectDescription: "Purchased a new chair and table")
        
        linkUserToParentProject(firstUser)
        
        print(firstUser)
        print(firstUser.searchForUserRelatedProjects())
        print(firstUser.printAllUsers())
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}