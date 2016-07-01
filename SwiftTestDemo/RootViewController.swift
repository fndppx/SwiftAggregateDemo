//
//  RootViewController.swift
//  SwiftTestDemo
//
//  Created by keyan on 16/6/29.
//  Copyright © 2016年 keyan. All rights reserved.
//

import UIKit
import Alamofire
import SwiftyJSON
class RootViewController: UIViewController {

    var dateArray:[AnyObject] = []
    var books = [TestModel]()
    @IBOutlet weak var tableView: UITableView!
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        self.tableView.separatorStyle = .SingleLine
        
        
        let URLString = "https://api.douban.com/v2/book/search"

        
        Alamofire.request(.GET, URLString, parameters: ["tag":"Swift","count":10]).validate().responseJSON { (respose ) in
            print("\(respose)")
            if let error = respose.result.error {
                print(error)
            } else if let value = respose.result.value,jsonArray = JSON(value)["books"].array {
                for json in jsonArray {
                    let book = TestModel()
                    book.title = json["title"].string ?? ""
                    book.subtitle = json["subtitle"].string ?? ""
                    book.image = json["image"].string ?? ""
                    self.books.append(book)
                }
                self.tableView.reloadData()
            }

        }
        
  
        

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    


}

//扩展
extension RootViewController: UITableViewDataSource
{
    
    
    func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        return self.books.count
        
    }
    
    func tableView(tableView: UITableView, heightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
        return 80
    }
    
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        var cell = tableView.dequeueReusableCellWithIdentifier("cell")
        let book = books[indexPath.row]
        if cell == nil
        {
            cell = UITableViewCell(style: UITableViewCellStyle.Subtitle, reuseIdentifier: "cell")
        }
        cell?.imageView?.sd_setImageWithURL(NSURL(string: book.image))
        cell?.textLabel?.text = book.title
        cell?.detailTextLabel?.text = book.subtitle

        return cell!
    }
    
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        
        
        
//        let nextVC  = HorSegmentViewController.init(nibName: "HorSegmentViewController", bundle: nil)
        let nextVC  = DetailDownImageController.init(nibName: "DetailDownImageController", bundle: nil)

        nextVC.navigationController?.navigationBarHidden = true;
        self.navigationController?.pushViewController(nextVC, animated: true)
        
        
        
    }
}