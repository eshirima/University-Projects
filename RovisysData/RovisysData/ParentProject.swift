//
//  ParentProject.swift
//  RovisysData
//
//  Created by Emil Shirima on 3/9/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

import UIKit
import RealmSwift

class ParentProject: Object
{
    // MARK: Member Variables
    private dynamic var projectName: String = String()
    private dynamic var submmittedBy: String = String()
    private dynamic var submissionDate: NSDate = NSDate()
    private dynamic var projectDescription: String = String()
    
    override static func primaryKey()->String
    {
        return "projectName"
    }
    
    // MARK: Getters
    func getParentProjectName()->String
    {
        return projectName
    }
    
    func getParentProjectSubmittedBy()->String
    {
        return submmittedBy
    }
    
    func getParentProjectSubmissionDate()->NSDate
    {
        return submissionDate
    }
    
    func getParentProjectDescription()->String
    {
        return projectDescription
    }
    
    // MARK: Setters
    func setParentProjectName(newParentProjectName: String)
    {
        projectName = newParentProjectName
    }
    
    func setParentProjectSubmittedBy(newProjectOwner: String)
    {
        submmittedBy = newProjectOwner
    }
    
    func setParentProjectSubmissionDate(newSubmissionDate: NSDate)
    {
        submissionDate = newSubmissionDate
    }
    
    func setParentProjectDescription(newProjectDescription: String)
    {
        projectDescription = newProjectDescription
    }
    
    func createParentProject(newProjectName: String, projectOwnerName: String, projectSubmissionDate: NSDate, newProjectDescription: String)
    {
        projectName = newProjectName
        submmittedBy = projectOwnerName
        
        submissionDate = projectSubmissionDate
        projectDescription = newProjectDescription
    }
    
    // POST: Saves the new project to Realm
    func saveNewProject(newParentProject: ParentProject)
    {
        let realmObject = try! Realm()
        try! realmObject.write({ () -> Void in
            realmObject.add(newParentProject)
            //TODO: Alert the user
            print("New Project was successfully added")
        })
    }
    
    // POST: Checks to see if passed project exists
    func doesParentProjectExist(projectDetails: ParentProject)->Bool
    {
        let searchParentProjectPredicate: NSPredicate = NSPredicate(format: "projectName = %@", projectDetails.projectName)
        let realmObject = try! Realm()
        let userElements = realmObject.objects(ParentProject).filter(searchParentProjectPredicate)
        print("User Results are \(userElements.count)")
        return userElements.count > 0 ? true : false
    }
    
    // POST: Prints all the projects stored in Realm
    func printAllParentProjects()->[ParentProject]
    {
        let realmObject = try! Realm()
        let allProjectsObjects = realmObject.objects(ParentProject)
        var allProjects: [ParentProject] = [ParentProject]()
        
        if allProjectsObjects.count > 0
        {
            for thisUser in allProjectsObjects
            {
                let project = thisUser as ParentProject
                allProjects.append(project)
            }
        }
        
        return allProjects
    }
}