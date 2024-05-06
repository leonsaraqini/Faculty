using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace IT_LAB_3.Models
{
    public class Hospital
    {
        [Key]
        public int Id { get; set; }
        [Required]
        public string Name { get; set; }
        [Required]
        public string Address { get; set; }
        [Required]
        public string ImgUrl { get; set; }
        public virtual ICollection<Doctor> doctors { get; set; }

        public Hospital()
        {
            doctors = new List<Doctor>();
        }
    }
}