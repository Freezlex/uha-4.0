package com.freezlex.microservice.web.controller;

import com.freezlex.microservice.dao.ProductDao;
import com.freezlex.microservice.model.Product;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class ProductController {

    @Autowired
    private ProductDao productDao;

    @RequestMapping(value = "/Products", method = RequestMethod.GET)
    public List<Product> listProducts() {
        return productDao.findAll();
    }

    @RequestMapping(value = "/Products/{id}", method = RequestMethod.GET)
    public Product displayProducts(@PathVariable int id) {
        return productDao.ProductFindById(id);
    }

    @PostMapping(value = "/Products")
    public void addProduct(@RequestBody Product product) {
        productDao.ProductSave(product);
    }

    @DeleteMapping(value = "/Products/{id}")
    public void delProduct(@PathVariable int id) {
        productDao.ProductDelete(id);
    }
}
