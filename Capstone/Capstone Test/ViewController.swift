//
//  ViewController.swift
//  Capstone Test
//
//  Created by Emil Shirima on 2/8/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

import UIKit
import RealmSwift

class ViewController: UIViewController, UITextFieldDelegate {
    
    @IBOutlet weak var userNameTextField: UITextField!
    @IBOutlet weak var passwordTextField: UITextField!
    @IBOutlet weak var titleTextField: UILabel!
    
    
    @IBOutlet weak var loginBtn: UIButton!
    
    let designerColor: UIColor = UIColor(red: 0.255, green: 0.294, blue: 0.361, alpha: 1.00)
    let cornerRadius: CGFloat = 20

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        initialDesignSetUp()
        
        let samplePerson = User()
//        samplePerson.userName = "admin"
//        samplePerson.passWord = "admin123"
        
//        print(samplePerson)
        
//        samplePerson.saveNewUser(samplePerson)
        
        print(samplePerson.printUsers())
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func initialDesignSetUp()
    {
        self.view.backgroundColor = designerColor
//        self.navigationController?.navigationBar.barTintColor = designerColor
        
        userNameTextField.borderStyle = UITextBorderStyle.RoundedRect
        passwordTextField.borderStyle = UITextBorderStyle.RoundedRect
        
        loginBtn.layer.cornerRadius = cornerRadius
        userNameTextField.layer.cornerRadius = cornerRadius
        passwordTextField.layer.cornerRadius = cornerRadius
        
        titleTextField.addCharactersSpacing(30, text: titleTextField.text!)
    }
    
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        
        textField.resignFirstResponder()
                
        if textField == userNameTextField
        { // Switch focus to other text field
            passwordTextField.becomeFirstResponder()
        }
        return true
    }
    
    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        view.endEditing(true)
        super.touchesBegan(touches, withEvent: event)
    }


}

