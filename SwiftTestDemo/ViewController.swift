//
//  ViewController.swift
//  SwiftTestDemo
//
//  Created by keyan on 16/6/29.
//  Copyright © 2016年 keyan. All rights reserved.
//

import UIKit

class ViewController: UIViewController,UITableViewDelegate {

    @IBOutlet weak var tableView: UITableView!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
    
        
        
        self.tableView.separatorStyle = .SingleLine
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    
    
    
    

}

extension ViewController: UITableViewDataSource
{
    
  
    func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        return 10
    
    }
    
    func tableView(tableView: UITableView, heightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
        return 80
    }
    
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        var cell = tableView.dequeueReusableCellWithIdentifier("cell")
        if cell == nil
        {
            cell = UITableViewCell(style: UITableViewCellStyle.Default, reuseIdentifier: "cell")
        }
        cell?.selectionStyle
        cell?.textLabel?.text = ("\(indexPath.row)")
        
        return cell!
    }
    
 
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        
        let nextVC  = HorSegmentViewController()
        
        self.navigationController?.pushViewController(nextVC, animated: true)
        
             
        
    }
}