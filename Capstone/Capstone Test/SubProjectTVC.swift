//
//  SubProjectTVC.swift
//  Capstone Test
//
//  Created by Emil Shirima on 2/9/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

import UIKit

class SubProjectTVC: UITableViewController {
    
    var expenseTitle: String?
    var subProjectTile: String?
    var subProjects: [String] = ["Computer Science", "Meeting", "Dinner", "Lunch", "Conference", "Electronics", "Mobile Phones"]
    var subProjectsTotal: [String] = ["$500", "$60.76", "$300.50", "$45.98", "$87.90", "$900.87", "$87.90"]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        ExpensesTVC.designTableView(self.tableView)
                
        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false

        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    // MARK: - Table view data source

    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        // #warning Incomplete implementation, return the number of sections
        return 1
    }

    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // #warning Incomplete implementation, return the number of rows
        return subProjects.count
    }

    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("reuseIdentifier", forIndexPath: indexPath)

        cell.textLabel?.text = subProjects[indexPath.row]
        cell.detailTextLabel?.text = "Total: " + subProjectsTotal[indexPath.row]

        return cell
    }

    // Override to support conditional editing of the table view.
    override func tableView(tableView: UITableView, canEditRowAtIndexPath indexPath: NSIndexPath) ->Bool{
        // Return false if you do not want the specified item to be editable.
        return true
    }

    // Override to support editing the table view.
    override func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath) {
        
    }
    
    override func tableView(tableView: UITableView, editActionsForRowAtIndexPath indexPath: NSIndexPath) -> [UITableViewRowAction]?
    {
        let deleteAction = UITableViewRowAction(style: .Default, title: "Delete") { (action:UITableViewRowAction, indexPath: NSIndexPath) -> Void in
            
            self.subProjects.removeAtIndex(indexPath.row)
            self.subProjectsTotal.removeAtIndex(indexPath.row)
            
            tableView.deleteRowsAtIndexPaths([indexPath], withRowAnimation: .Fade)
        }
        
        let editAction = UITableViewRowAction(style: .Normal, title: "Edit") { (action: UITableViewRowAction, indexPath: NSIndexPath) -> Void in
            
            // record the name of the subProject for segue use
            self.subProjectTile = self.subProjects[indexPath.row]
            
            self.performSegueWithIdentifier("expenseDetailView", sender: self)
        }
        
        editAction.backgroundColor = UIColor(red: 0.451, green: 0.851, blue: 0.620, alpha: 1.00)
        
        return [deleteAction, editAction]
    }
    
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        
        if let identifier = segue.identifier
        {
            switch identifier
            {
            case "expenseDetailView":
                if let expenseDetailVC = segue.destinationViewController as? ExpenseDetailVC
                {
                    if let indexPath = tableView.indexPathForSelectedRow?.row
                    {
                        expenseDetailVC.title = subProjects[indexPath]
                    }
                    
                    else // this portion is reached when the action performed is not a selection i.e. Edit button is pressed
                    {
                        expenseDetailVC.title = subProjectTile
                    }
                }
            default:
                break
            }
        }
    }
}