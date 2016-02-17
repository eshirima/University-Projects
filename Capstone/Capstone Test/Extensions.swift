//
//  Extensions.swift
//  Capstone Test
//
//  Created by Emil Shirima on 2/8/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

import Foundation
import UIKit

extension UILabel
{
    func addCharactersSpacing(spacing:CGFloat, text:String)
    {
        let attributedString = NSMutableAttributedString(string: text)
        
        attributedString.addAttribute(NSKernAttributeName, value: spacing, range: NSMakeRange(0, text.characters.count))
        
        self.attributedText = attributedString
    }
}