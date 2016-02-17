//
//  ExpensesTVC.swift
//  Capstone Test
//
//  Created by Emil Shirima on 2/8/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

import UIKit

class ExpensesTVC: UITableViewController {
    
    var allProjects: [String] = ["Recruiting", "Sales", "Personal", "Manufacturing", "Reservation", "Rental", "Accomodation", "Lifestyle", "Utensils"]
    var subProjectsTotal: [String] = ["15", "2", "43", "80", "10", "3", "12", "69", "30"]

    override func viewDidLoad() {
        super.viewDidLoad()
        
        ExpensesTVC.designTableView(self.tableView)

        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false

        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem()
    }
    
    static func designTableView(passedTableView: UITableView)
    {
        // removes the empty rows in the table
        passedTableView.tableFooterView = UIView(frame: CGRect.zero)
        
        passedTableView.backgroundColor = UIColor(red: 0.298, green: 0.302, blue: 0.380, alpha: 1.00)
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
        return allProjects.count
    }

    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCellWithIdentifier("reuseIdentifier", forIndexPath: indexPath)
        
        cell.textLabel?.text = allProjects[indexPath.row]
        cell.detailTextLabel?.text = subProjectsTotal[indexPath.row] + " Projects"

        return cell
    }
    
    override func tableView(tableView: UITableView, editActionsForRowAtIndexPath indexPath: NSIndexPath) -> [UITableViewRowAction]?
    {
        let editAction = UITableViewRowAction(style: .Default, title: "Delete Project") { (action:UITableViewRowAction, indexPath: NSIndexPath) -> Void in
            
            self.allProjects.removeAtIndex(indexPath.row)
            self.subProjectsTotal.removeAtIndex(indexPath.row)
            
            tableView.deleteRowsAtIndexPaths([indexPath], withRowAnimation: .Fade)
        }
        
        return [editAction]
    }
    
    
    // Override to support conditional editing of the table view.
    override func tableView(tableView: UITableView, canEditRowAtIndexPath indexPath: NSIndexPath) -> Bool {
        // Return false if you do not want the specified item to be editable.
        return true
    }
    
    //MARK: Needed for the swipe gesture
    // Override to support editing the table view.
    override func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath)
    {
        
    }
    
//    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
//        let cell = tableView.cellForRowAtIndexPath(indexPath)
//        cell?.backgroundColor = UIColor(red: 0.294, green: 0.400, blue: 0.420, alpha: 1.00)
//    }
//
//    override func tableView(tableView: UITableView, didDeselectRowAtIndexPath indexPath: NSIndexPath) {
//        let cell = tableView.cellForRowAtIndexPath(indexPath)
//        cell?.backgroundColor = UIColor(red: 0.298, green: 0.302, blue: 0.380, alpha: 1.00)
//    }

    /*
    // Override to support rearranging the table view.
    override func tableView(tableView: UITableView, moveRowAtIndexPath fromIndexPath: NSIndexPath, toIndexPath: NSIndexPath) {

    }
    */

    /*
    // Override to support conditional rearranging of the table view.
    override func tableView(tableView: UITableView, canMoveRowAtIndexPath indexPath: NSIndexPath) -> Bool {
        // Return false if you do not want the item to be re-orderable.
        return true
    }
    */

    
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        
        if let identifier = segue.identifier
        {
            switch identifier
            {
                case "segueToSubProject":
                if let subProjectTVC = segue.destinationViewController as? SubProjectTVC
                {
                    if let indexPath = tableView.indexPathForSelectedRow?.row
                    {
                        subProjectTVC.title = self.allProjects[indexPath]
                        subProjectTVC.expenseTitle = self.allProjects[indexPath]
                    }
                }
            default:
                break
            }
        }
    }
}