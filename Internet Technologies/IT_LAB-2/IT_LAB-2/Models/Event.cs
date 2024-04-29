using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace IT_LAB_2.Models
{
    public class Event
    {
        public int Id { get; set; }
        public string Name { get; set; }

        [MinLength(5, ErrorMessage = "Smaller than 5!!!"), MaxLength(30, ErrorMessage = "Larger than 30!!!")]
        public string Location { get; set; }
    }
}