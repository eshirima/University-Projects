//
//  LineItems.swift
//  RovisysData
//
//  Created by Emil Shirima on 3/9/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

import UIKit
import RealmSwift

class LineItems: Object
{
    // // MARK: Member Variables
    dynamic var lineItemID: String = NSUUID().UUIDString // Primary Key
    dynamic var itemParentName: String = ParentProject().getParentProjectName() // Foreign Key
    
    dynamic var itemReceipt: NSData = NSData()
    dynamic var itemCost: Int = Int()
    
    override static func primaryKey()->String
    {
        return "lineItemID"
    }
}